class Person {
    constructor(name, age, gender) {
        this.name = name;
        this.age = age;
        this.gender = gender;
    }

    showPersonInfo = function () {
        console.log(`name: ${this.name}\n age: ${this.age}\n gender: ${this.gender}`);
    }
}

class Student extends Person {
    constructor(name, age, gender, grade) {
        super(name, age, gender);
        this.grade = grade;
    }

    showStudentInfo = function () {
        this.showPersonInfo();
        console.log(`grade: ${this.grade}`);
    }
}

class Employee extends Person {
    constructor(name, age, gender, daySalary) {
        super(name, age, gender);
        this.daySalary = daySalary;
    }

    calculateOvertime = function (hours) {
        if (this.age < 18) {
            return 0;
        }
        else {
            return hours * (this.daySalary / 8) * 1.5
        }

    }

    showEmployeeInfo = function () {
        this.showPersonInfo();
        console.log(`daySalary: ${this.daySalary}`);
    }
}

const array = new Array(10);

const ivan = new Person('Ivan', 24, "male");
const drago = new Employee("Drago", 23, 'male', 50);
const pencho = new Student("Pencho", 23, 'male', 253);
const gosho = new Person('Gosho', 24, 'male');
const dimitur = new Employee("Mitko", 17, 'male', 50);
const penko = new Student("Penko", 23, 'male', 253);

array.push(ivan, drago, pencho, gosho, dimitur, penko);

array.forEach(personObj => {
    if (personObj instanceof Student) {
        personObj.showStudentInfo();
    } else if (personObj instanceof Employee) {
        personObj.showEmployeeInfo();
        console.log(`Overtime bonus: ${personObj.calculateOvertime(2)}`);
    } else if (personObj instanceof Person) {
        personObj.showPersonInfo();
    }
});

array.filter(obj => obj instanceof Employee)
    .forEach(employee => console.log(`Overtime bonus: ${employee.calculateOvertime(2)}`));