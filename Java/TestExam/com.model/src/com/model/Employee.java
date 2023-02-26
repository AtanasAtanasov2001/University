package com.model;

public class Employee {
    private String name;
    private double salary;

    public Employee(String name, double salary) {
        setName(name);
        setSalary(salary);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name != null ? name : "No Name";
    }

    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        this.salary = salary > 0 ? salary : 1000;
    }

    @Override
    public String toString() {
        return String.format("Name: %s, Salary: %.2f", name, salary);
    }
}
