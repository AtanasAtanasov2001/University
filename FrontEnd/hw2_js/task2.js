class Cat {
    constructor(name, breed, age) {
        this.name = name;
        this.breed = breed;
        this.age = age;
    }
}

function sortCats(arrayOfCats, criterion) {
    switch (criterion) {
      case 'name':
        return arrayOfCats.sort((a, b) => a.name.localeCompare(b.name));
      case 'breed':
        return arrayOfCats.sort((a, b) => a.breed.length - b.breed.length);
      case 'years':
        return arrayOfCats.sort((a, b) => a.years - b.years);
      case 'all':
        return arrayOfCats.sort((a, b) => (a.name.length + a.breed.length + a.years) - (b.name.length + b.breed.length + b.years));
      default:
        return arrayOfCats;
    }
  }

const arr = [
    {
        "name": "Tina",
        "breed": "Maine Coon",
        "age": 2
    },
    {
        "name": "Annie",
        "breed": "Maine Coon",
        "age": 7
    },
    {
        "name": "Polly",
        "breed": "Brittish shorthair",
        "age": 3
    }
];

sortCats(arr, 'breed');
console.log(arr);