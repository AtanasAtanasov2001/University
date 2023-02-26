#include "interface.hpp"
#include<iostream>

int main() {
//    "Uspeshnia     -        Gosho        
//                                                Uspeshnia -     Misho    
//                         Gosho    -                Pesho
//     Gosho -                Dancho   
//                                     Pesho - Alex
//                                                                         Dancho-Boris
//                      Dancho-                -                        Kamen
//                     Uspeshnia                    - Slavi
// Slavi         -                        Slav1
//             Slavi         -                 Slav2
//             Slav1-                Mecho                       
//                                 Mecho                                -        Q12Adl" 
//"Uspeshnia-Gosho\nUspeshnia-Misho\nUspeshnia-Slavi\nGosho-Dancho\nGosho-PeshonSlavi-Slav1\nSlavi-Slav2\nDancho-Boris\nDancho-Kamen\nPesho-Alex\nSlav1-Mecho\nMecho-Q12Adl"
//Hierarchy_tree tree("Uspeshnia-Gosho\nUspeshnia-Misho\nUspeshnia-Slavi\nGosho-Dancho\nGosho-Peshon\nSlavi-Slav1\nSlavi-Slav2\nDancho-Boris\nDancho-Kamen\nPesho-Alex\nSlav1-Mecho\nMecho-Q12Adl\n");
   //tree.insert("Ivan", "Uspeshnia");
   // tree.insert("Pesho", "Ivan");
   // tree.insert("Pesho1", "Ivan");
   // tree.insert("Pesho2", "Ivan");
   // tree.insert("Pesho5","Pesho");
   // tree.insert("Pesho4","Pesho5");
   // tree.insert("Pesho8","Pesho5");
//std::cout << tree.print();
// std::cout << tree.getRoot()->data;

//    // //u->i
//    // //i->p5, i->p1, i->p2
//    // ////p->p5
//    // //p5->p4, p5->p8
// std::cout << tree.findNode("Ivan")->data;
   // std::cout << tree.find("Uspeshniya");
   // std::cout << tree.remove("Pesho");
   // std::cout << tree.find("Pesho");
   // std::cout << tree.num_direct_employees("Ivan");
   // std::cout << tree.num_indirect_employees("Ivan");
   // std::cout << tree.getHeight();

//======================================

Hierarchy company("Uspeshnia-Gosho\nUspeshnia-Misho\nUspeshnia-Slavi\nGosho-Dancho\nGosho-Pesho\nSlavi-Slav1\nSlavi-Slav2\nDancho-Boris\nDancho-Kamen\nPesho-Alex\nSlav1-Mecho\nMecho-Q12Adl\n");
// company.hire("Ivan", "Uspeshniya");
// company.hire("Ivan1", "Uspeshniya");
// company.hire("Ivan2", "Uspeshniya");
// company.hire("Pesho", "Ivan");
// company.hire("Pesho1", "Ivan");
// company.hire("Shaip", "Pesho");
// std::cout << company.longest_chain() << "\n";
// std::cout << company.find("Slavi") << "\n";
// std::cout << company.num_employees() << "\n";
// std::cout << company.manager("Boris") << "\n";
// std::cout << company.num_subordinates("Uspeshnia") << "\n";
// std::cout << (int)company.getSalary("Uspeshniya") << "\n";
// // // //std::cout << company.getSalary("Peshko") << "\n";
// std::cout << company.fire("Pesho") << "\n";
// std::cout << company.print() << "\n";
// std::cout << company.num_overloaded() << "\n";

company.saveToFile();
// std::cout << company.print();
// company.incorporate();
// //company.modernize();
// std::cout << company.print(); 
//company.start();

return 0;

}