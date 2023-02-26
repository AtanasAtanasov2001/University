#include <iostream>
#include "Seminar/linkedStack/linkedStack_mine.h"
// class queue
// {
//   public:
//   int batPesho;
//   queue() : batPesho(-1){}
  
//   struct node
//   {
//       int num;
//       node() : num(5){}
//   } *n1 ;
// };



int main() {

  // struct node
  // {
  //     int num;

  //     node(int _num) : num(_num){
  //       std::cout << "kuru na muru" << num << std::endl;
  //     }
  // } *n1 ;
  // // queue  q1;
  // // std::cout << q1.n1->num << std::endl;
  // // std::cout << q1.batPesho << std::endl;
  // n1 = new node(4);
  // std::cout << n1->num << std::endl;

  LinkedStack ls;
  ls.push(4);
  ls.push(5);
  ls.push(6);
  ls.push(7);
  ls.push(8);
  ls.push(9);
  LinkedStack ls1(ls);
  std::cout << "starting..." << std::endl;
  while (!ls1.isEmpty()) {
    std::cout << ls1.pop() << std::endl;
  }
  while (!ls.isEmpty()) {
    std::cout << ls.pop() << std::endl;
  }
  // std::cout << ls1.pop() << std::endl;
  // std::cout << ls.pop() << std::endl;
  // std::cout << ls.top() << std::endl;
  // std::cout << ls1.pop() << std::endl;
  std::cout << "end!" << std::endl;
  return 0;
}