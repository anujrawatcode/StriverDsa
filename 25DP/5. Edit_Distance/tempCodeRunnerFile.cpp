
// int editDis_Rc(string s1, string s2, int n1, int n2)
// {
//     if (n1 == 0)
//         return n2;
//     if (n2 == 0)
//         return n1;
//     if (s1[n1 - 1] == s2[n2 - 1])
//         return editDis_Rc(s1, s2, n1 - 1, n2 - 1);
//     else
//         return 1 + min(editDis_Rc(s1, s2, n1 - 1, n2),
//                        editDis_Rc(s1, s2, n1, n2 - 1),
//                        editDis_Rc(s1, s2, n1 - 1, n2 - 1));
// }
