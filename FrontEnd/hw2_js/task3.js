function Task3(strings) {
    var palindromes = [];
    for (var i = 0; i < strings.length; i++) {
      var str = strings[i];
      var isPalindrome = true;
      for (var j = 0; j < str.length / 2; j++) {
        if (str[j] !== str[str.length - 1 - j]) {
          isPalindrome = false;
          break;
        }
      }
      if (isPalindrome) {
        palindromes.push(str);
      }
    }
    return palindromes;
  }

const arr = ["abccba", "lalala", "something", "123321", "debel lebed"];

const palindromes = Task3(arr);
console.log(palindromes);