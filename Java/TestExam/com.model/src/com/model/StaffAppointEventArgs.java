package com.model;

public class StaffAppointEventArgs {
    private Staff newStaff;
    private double newSalary;

    public StaffAppointEventArgs(Staff newStaff, double newSalary) {
        this.newStaff = newStaff;
        this.newSalary = newSalary;
    }

    public Staff getNewStaff() {
        return newStaff;
    }

    public void setNewStaff(Staff newStaff) {
        this.newStaff = newStaff;
    }

    public double getNewSalary() {
        return newSalary;
    }

    public void setNewSalary(double newSalary) {
        this.newSalary = newSalary > 0 ? newSalary : 1100;
    }
}
