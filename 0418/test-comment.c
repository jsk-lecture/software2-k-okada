/* test0.c */
#include <stdio.h>
/*
* このファイルを改変し適切なコメント(10行以上）を付けること
*/
// 入力：整数　i， i
// 出力：整数
// 機能：i と j の積
int test(int i, int j) {
  return (i * j);
}

int main(int argc, char *argv) {
  int i, j;
  int k;
  i = 3; // i と j にそれぞれ3と2を代入する
  j = 2;
  // test 関数を呼び出し，返り値をkに代入する
  k = test(i, j);
  // kは6が入っているはず．
  if (k > 5) { // k が５より大きければ '>5' を表示，そうでないなら '<=5' を表示．
    // ここではkが6なので，'>5'が表示されているはず．
    printf(">5\n");
  } else {
    printf("<=5\n");
  }
  return 0;
}
