
const sumArrays = (arr1, arr2) => {
  // your code here
  function flatten(arr) {
    return arr.reduce(function (flat, toFlatten) {
      return flat.concat(Array.isArray(toFlatten) ? flatten(toFlatten) : toFlatten);
    }, []);
  }

  if (arr1.some(function(elem) {
    return (typeof(elem) !== "number" && !Array.isArray(elem) );}
               ) 
    || arr2.some(function(elem) {
    return (typeof(elem) !== "number" && !Array.isArray(elem) );}
                )) 
    {
      const concated = arr1.concat(arr2).filter(element => typeof(element) === 'number')
      return (Math.min(...(concated)) === Infinity ? 'No number type found in input arrays' : 'Min number found is ' + Math.min(...(concated)));
  }


  while(arr1.some(function(elem) {
    return Array.isArray(elem);
  }) ){
    arr1 = flatten(arr1);
  }

  while(arr2.some(function(elem) {
    return Array.isArray(elem);
  }) ){
    arr2 = flatten(arr2);
  }

  let set = new Set();

  arr1.forEach(element => {
    if(arr2.includes(element)) {
      set.add(element);
    }
  }); 
  // console.log(set);
  return Array.from(set).filter(element => element % 3 === 0).reduce((element, acc) => element + acc, 0) ;
  
};

console.log(sumArrays([1, 2, 3, 4, 5, 6, 7, 8, 9], [7, 8, 6, 10, 11, 12, 9])); // 15
console.log(sumArrays([1, 2, [3, [4, [5, [6]]]]], [4, [[[[[[6]]]]]]])); // 6
console.log(sumArrays([1, 2, 3, () => {}], [3, 4])); // Min number found is 1
console.log(sumArrays([() => {}], ["1"])); // No number type found in input arrays
console.log(sumArrays([() => {}], [{}])); // No number type found in input arrays

const input = [
  { name: "Martin", mark: 4, course: "SI" },
  { name: "Elena", mark: 6, course: "IS" },
  { name: "Tsani", mark: 5, course: "IS" },
  { name: "Niya", mark: 2.9, course: "IS" },
  { name: "Ivo", mark: 2.5, course: "KN" }
];


const getTopStudents = students => {
  // your code here
  return students.filter(student => student.mark > 5.5);
};

const getLowStudents = students => {
  // your code here
  return students.filter(student => student.mark < 3);
};


const orderStudents = (students, criteria) => {
  // your code here
  
  if(criteria && criteria.course){
    students = students.filter(student => {
      return student.course === criteria.course;
    });
  }
  if(!criteria || !criteria.type || criteria.type === 'ascending') {
    students.sort(function(current, next) {
      return current.mark <= next.mark ? -1 : 1;
    });
  }else if (criteria && criteria.type === 'descending') {
    students.sort(function(current, next) {
      return next.mark > current.mark ? 1 : -1;
    });
  }

  return students.map(student => {
    return {
      ...student,
      mark: student.mark >= 3 ? Math.ceil(student.mark): 2
    }
  })
};

console.log('Top: ', getTopStudents(input));
console.log('Low: ', getLowStudents(input));
console.log('ascending all: ', orderStudents([...input]));
console.log('descending all: ', orderStudents([...input], { type: "descending" }));
console.log('ascending IS: ', orderStudents([...input], { course: "IS"}));
console.log('descending IS: ', orderStudents([...input], { type: "descending", course: "IS" }));
console.log('ascending: IS', orderStudents([...input], { type: "ascending", course: "IS" }));

export { sumArrays, getTopStudents, getLowStudents, orderStudents };
