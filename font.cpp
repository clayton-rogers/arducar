#include "font.h"

const int FONT_WIDTH = 6;

static byte font[] PROGMEM = {
// 0   NUL
// 1   SOH
// 2   STX
// 3   ETX
// 4   EOT
// 5   ENQ
// 6   ACK
// 7   BEL
// 8   BS
// 9   HT
// 10  LF line feed
// 11  VT vertical tab
// 12  FF form feed
// 13  CR carriage return
// 14  SO shift out
// 15  SI shift in
// 16  DLE
// 17  DC1
// 18  DC2
// 19  DC3
// 20  DC4
// 21  NAK
// 22  SYN
// 23  ETB
// 24  CAN cancel
// 25  EM
// 26  SUB
// 27  ESC
// 28  FS
// 29  GS
// 30  RS
// 31  US
// 32  " " space
// 33  !
// 34  "
// 35  #
// 36  $
// 37  %
// 38  &
// 39  '
// 40  (
// 41  )
// 42  *
// 43  +
// 44  ,
// 45  -
// 46  .
// 47  /
// 48  0
// 49  1
// 50  2
// 51  3
// 52  4
// 53  5
// 54  6
// 55  7
// 56  8
// 57  9
// 58  :
// 59  ;
// 60  <
// 61  =
// 62  >
// 63  ?
// 64  @
// 65  A
// 66  B
// 67  C
0x41, 0x7F, 0x41, 0x41, 0x3E, 0x00, // 68  D
0x7F, 0x49, 0x49, 0x49, 0x41, 0x00, // 69  E
// 70  F
// 71  G
0x7f, 0x08, 0x08, 0x08, 0x7f, 0x00, // 72  H
// 73  I
// 74  J
// 75  K
0x7F, 0x40, 0x40, 0x40, 0x40, 0x00, // 76  L
// 77  M
// 78  N
0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00, // 79  O
// 80  P
// 81  Q
0x7F, 0x09, 0x19, 0x29, 0x46, 0x00, // 82  R
// 83  S
// 84  T
// 85  U
// 86  V
0x3F, 0x40, 0x38, 0x40, 0x3F, 0x00, // 87  W
// 88  X
// 89  Y
// 90  Z
// 91  [
// 92  \
// 93  ]
// 94  ^
// 95  _
// 96  `
// 97  a
// 98  b
// 99  c
// 100 d
// 101 e
// 102 f
// 103 g
// 104 h
// 105 i
// 106 j
// 107 k
// 108 l
// 109 m
// 110 n
// 111 o
// 112 p
// 113 q
// 114 r
// 115 s
// 116 t
// 117 u
// 118 v
// 119 w
// 120 x
// 121 y
// 122 z
// 123 {
// 124 |
// 125 }
// 126 ~
// 127 DEL delete
}

static byte buffer[FONT_WIDTH];

Font_char_t FONT_get_char(char c) {

	// TODO:

	return buffer;
}
