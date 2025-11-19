int translate(char roman) {
  switch (roman) {
  case 'I':
    return 1;
  case 'V':
    return 5;
  case 'X':
    return 10;
  case 'L':
    return 50;
  case 'C':
    return 100;
  case 'D':
    return 500;
  default:
    return 1000;
  }
}

int romanToInt(char *s) {
  int total = 0;
  int prev = 0;
  while (*s != '\0') {
    int num = translate(*s);
    if (num > prev) {
      total -= prev * 2;
    }
    total += num;
    prev = num;
    ++s;
  }

  return total;
}
