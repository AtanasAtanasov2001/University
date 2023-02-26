# Задача 1
  ## Условие
  Дадени са 2 масива. Намерете общите елементи на тези два масива, като всеки от тях трябва да се дели на 3. Резултатът от не трябва да съдържа повтарящи се елементи. Върнете сбора на елементите на масива, резултат от предишните действия. 
      - Ако някой от масивите за вход съдържа елемент от тип `Array`, първо направете едномерен масив и изпълнете условията върху новосъздадения масив. (може да имаме много нива на вложеност)
      - Ако някой от масивите за вход съдържа елемент от друг тип (нито `Array`, нито число) да се върне най-малкото число намерено в масива форматирано като `Min number found is _число_`. Ако масивът не сържа числа, нека върне `No number type found in input arrays`
  ## Вход
    sumArrays([1, 2, 3, 4, 5, 6, 7, 8, 9], [7, 8, 6, 10, 11, 12, 9]);

  ## Изход
    15
  ## Обяснение
    1. Имаме 2 масива за вход
      - [1, 2, 3, 4, 5, 6, 7, 8, 9]
      - [7, 8, 6, 10, 11, 12, 9]

    2. Общите елементи между двата масива са [6, 9, 7, 8].
    3. Тези, които се делят на 3 са [6, 9]
    4. Резултатът от сбора на тези елементи е 15.

  ## Примери
    console.log(sumArrays([1, 2, 3, 4, 5, 6, 7, 8, 9], [7, 8, 6, 10, 11, 12, 9])); // 15
    console.log(sumArrays([1, 2, [3, [4, [5, [6]]]]], [4, [[[[[[6]]]]]]])); // 6
    console.log(sumArrays([1, 2, 3, () => {}], [3, 4])); // Min number found is 1
    console.log(sumArrays([() => {}], ["1"])); // No number type found in input arrays
    console.log(sumArrays([() => {}], [{}])); // No number type found in input arrays

  ## Решение
    Попълнете решението си в `index.js` файла в тялото на метода `sumArrays`

# Задача 2

Напишете метод, който сортира масив от обекти по дадени критерии.

## Вход

Ще получите масив от студенти със следните свойства: име, оценка, специалност
```js
{
  name: "Martin"
  mark: 4,
  course: "SI"
}
```
Примерен вход
```js
const input = [
  { name: "Martin", mark: 4, course: "SI" },
  { name: "Elena", mark: 6, course: "IS" },
  { name: "Tsani", mark: 5, course: "IS" },
  { name: "Niya", mark: 2.9, course: "IS" },
  { name: "Ivo", mark: 2.5, course: "KN" }
];
```

- `getTopStudents`: Имплементирайте метод, който връща всички студенти отличници. (над 5.5)
- `getLowStudents`: Имплементирайте метод, който връща всички, който имат оценка под 3.
- `orderStudents`: Имплементирайте метод, който връща всички студенти от дадена специалност
  - Ако не е подадена специалност да се вземат предвид всички студенти от списъка
  - Ако не е подаден втори параметер да се започва от най-ниската оценка
  - Ако е подаден втори параметер 'descending' да се започва от най-високата оценка
  - В резултата за оценките на студентите да бъдат само кръгли числа (т.е. 2.9 => 2, но 3.9 => 4)

## Примери `getTopStudents` и `getLowStudents`

```js
console.log('Top: ', getTopStudents(input));
console.log('Low: ', getLowStudents(input));
```
<img width="366" alt="image" src="https://user-images.githubusercontent.com/5821279/205442186-f9a9bcfc-f5ad-4646-afb5-3cfa177935f9.png">


## Примери `orderStudents`

```js
console.log('ascending all: ', orderStudents([...input]));
```
<img width="438" alt="image" src="https://user-images.githubusercontent.com/5821279/205441861-b9888f88-a576-4eb4-9312-8c0121acf770.png">


```js
console.log('descending all: ', orderStudents([...input], { type: "descending" }));
```
<img width="433" alt="image" src="https://user-images.githubusercontent.com/5821279/205441880-cca91700-feba-4add-8fb2-09a6676dbae2.png">


```js
console.log('ascending IS: ', orderStudents([...input], { course: "IS"}));
```

<img width="435" alt="image" src="https://user-images.githubusercontent.com/5821279/205441905-0e15dc9b-136e-4614-803a-77927246d1c4.png">


```js
console.log('descending IS: ', orderStudents([...input], { type: "descending", course: "IS" }));
```
<img width="438" alt="image" src="https://user-images.githubusercontent.com/5821279/205441909-81033fcd-bb62-4a92-ba34-e7311d69b806.png">



```js
console.log('ascending: IS', orderStudents([...input], { type: "ascending", course: "IS" }));
```
<img width="412" alt="image" src="https://user-images.githubusercontent.com/5821279/205441921-f28a6f0d-5027-48ea-ab9b-0b42aa0dc8f4.png">

