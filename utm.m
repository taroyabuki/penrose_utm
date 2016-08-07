$RecursionLimit = Infinity;

decodeDecimal[n_] :=
 Reap[decodeBinary[Join[{1, 1, 0}, IntegerDigits[n, 2], {1, 1, 0}]]][[2, 1]]

decodeBinary[{}] := {}
decodeBinary[{0, x___}] := (Sow[0]; decodeBinary[{x}])
decodeBinary[{1, 0, x___}] := (Sow[1]; decodeBinary[{x}])
decodeBinary[{1, 1, 0, x___}] := (Sow[R]; decodeBinary[{x}])
decodeBinary[{1, 1, 1, 0, x___}] := (Sow[L]; decodeBinary[{x}])
decodeBinary[{1, 1, 1, 1, 0, x___}] := (Sow[STOP]; decodeBinary[{x}])

toTriple[{x_}] := {0, 0, x}
toTriple[{1, x_}] := {0, 1, x}
toTriple[{x_, y_, z_}] := {x, y, z}
toTriple[x_] := Prepend[Take[x, -2], FromDigits[Drop[x, -2], 2]]

makeRuleTable[in_] :=
 Partition[
  Map[toTriple,
   With[{tmp = Split[in, And[# =!= R, # =!= L, # =!= STOP] &]},
    If[OddQ[Length[tmp]], Append[tmp, {R}], tmp]]],
  2]

makeRule[decodedList_] :=
 MapIndexed[With[{i = First[#2] - 1},
     {Quotient[i, 2], Mod[i, 2]} -> toTriple[#1]] &,
   Split[decodedList, 
    And[# =!= R, # =!= L, # =!= STOP] &]] /. {L -> -1, R -> 1, STOP -> 0}

tm[n_Integer, rightTape_List, stepLimit_: Infinity] := tm[makeRuleTable[decodeDecimal[n]], rightTape, stepLimit]

tm[ruleTable_List, rightTape_List, stepLimit_: Infinity] := Module[{
   state = 0,
   head = First[rightTape],
   rTape = Rest[rightTape],
   lTape = {},
   rule,
   step = 0,
   rTable = ruleTable /. {L -> -1, STOP -> 0, R -> 1} (*高速化のため*)
   },
  While[step++ < stepLimit,
   rule = rTable[[state + 1, head + 1]];
   state = rule[[1]];
   head = rule[[2]];
   
   Switch[rule[[3]],(*move*)
    1,(*right move*)
    AppendTo[lTape, head];
    If[Length[rTape] == 0, head = 0,
     head = First[rTape];
     rTape = Rest[rTape]],
     
    -1,(*left move*)
    PrependTo[rTape, head];
    If[Length[lTape] == 0, head = 0,
     head = Last[lTape];(*並び方を反対にして実装しても速くはならない*)
     lTape = Drop[lTape, -1]],
     
    0,(*STOP*)
    Break[]]];
    
  If[step <= stepLimit,
   AppendTo[lTape, head];
   {If[MemberQ[lTape, 1],(*左に並ぶ0を削除する*)
     FixedPoint[If[First[#] == 0, Rest[#], #] &, lTape], {0}], state, step},
   {Null, Null, stepLimit}]]

stopQ[pre_, now_] := pre[[1, 3]] != now[[1, 3]]

minmax[in_] := With[{o = in[[1, 3]] - in[[1, 2]]},
  {o, o + Length[in[[2, 1]]] - 1}]

align[result_] := Map[
  With[{delta = Abs[minmax[Last[result]] - minmax[#]]},
    Join[
     Table[0, delta[[1]]],
     MapAt[If[# == 1, Red, Blue] &, #[[2, 1]], #[[1, 2]]],
     Table[0, delta[[2]]]]] &,
  result]

alignPlot[result_] := ArrayPlot[align[result]]

plot[result_] := ArrayPlot[Map[
   MapAt[If[# == 1, Red, Blue] &, #[[2]], #[[1, 2]]] &,
   result]]

tmTest[n_, initTape_] :=
 NestWhileList[
  TuringMachine[makeRule[decodeDecimal[n]]],
  {{0, 1, 0}, {initTape, 0}},
  stopQ,
  2]

un1 = 177642;

xn2 = 10389728107;

un2 = 1492923420919872026917547669;

xn1 = 450813704461563958982113775643437908;

euc = 267556252842584231926905232066896095708779077170409889426;

u=7244855335339317577198395039615711237952360672556559631108144796606505059404241090310483613632359365644443458382226883278767626556144692814117715017842551707554085657689753346356942478488597046934725739988582283827795294683460521061169835945938791885546326440925525505820555989451890716537414896033096753020431553625034984529832320651583047664142130708819329717234151056980262734686429921838172157333482823073453713421475059740345184372359593090640024321077342178851492760797597634415123079586396354492269159479654614711345700145048167337562172573464522731054482980784965126988788964569760906634204477989021914437932830019493570963921703904833270882596201301773727202718625919914428275437422351355675134084222299889374410534305471044368695876405178128019437530813870639942772823156425289237514565443899052780793241144826142357286193118332610656122755531810207511085337633806031082361675045635852164214869542347187426437544428790062485827091240422076538754264454133451748566291574299909502623009733738137724162172747723610206786854002893566085696822620141982486216989026091309402985706001743006700868967590344734174127874255812015493663938996905817738591654055356704092821332221631410978710814599786695997045096818419062994436560151454904880922084480034822492077304030431884298993931352668823496621019471619107014619685231928474820344958977095535611070275817487333272966789987984732840981907648512726310017401667873634776058572450369644348979920344899974556624029374876688397514044516657077500605138839916688140725455446652220507242623923792115253181625125363050931728631422004064571305275802307665183351995689139748137504926429605010013651980186945639498;
