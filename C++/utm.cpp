#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <chrono>
#include "utm.h"

using namespace std;

int main()
{
  auto t0 = std::chrono::high_resolution_clock::now();
  
  auto utm = penrose::emulator<vector<int>>();
  //auto utm = penrose::emulator<list<int>>();
  //auto utm = penrose::emulator<string>();

  utm.emulate(penrose::un1, { 1, 1, 1 });                                                     //UN(3 + 1)
  //utm.emulate(penrose::un2, { 1, 1, 1, 1, 1, 1 });                                          //UN(6 * 2)
  //utm.emulate(penrose::xn1, { 1, 0, 1, 0, 1, 1, 0 });                                       //XN(3 + 1)
  //utm.emulate(penrose::xn2, { 1, 0, 1, 0, 0, 1, 1, 0 });                                    //XN(6 * 2)
  //utm.emulate(penrose::euc, { 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 });            //UN(LCD(6, 8))
  //utm.emulate(penrose::utm, penrose::un1, { 1 });                                           //UTM(UN(1 + 1))
  //utm.emulate(penrose::utm, penrose::un2, { 1 });                                           //UTM(UN(1 * 2))
  //utm.emulate(penrose::utm, penrose::xn1, { 1, 0, 1, 1, 0 });                               //UTM(XN(1 + 1))
  //utm.emulate(penrose::utm, penrose::xn2, { 1, 0, 1, 1, 0 });                               //UTM(XN(1 * 2))
  //utm.emulate(penrose::utm, penrose::euc, { 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 });//UTM(UN(LCD(6, 8)))
  
  auto t1 = std::chrono::high_resolution_clock::now();
  cout << "steps: " << utm.getSteps() << endl;
  cout << "max tape length: " << utm.getMaxTapeLength() << endl;
  cout << "left tape: " << utm.getLTape() << endl;
  cout << "time: " << std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count() / 1000. << endl;
  return 0;
}