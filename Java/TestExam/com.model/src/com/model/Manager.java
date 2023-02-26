package com.model;

import java.security.InvalidParameterException;

public class Manager extends Employee {
    private String manageDeptName;
    private StaffAppointHandler staffAppoint;

    public Manager(String name, double salary, String manageDeptName) {
        super(name, salary);
        setManageDeptName(manageDeptName);
    }

    public String getManageDeptName() {
        return manageDeptName;
    }

    public void setManageDeptName(String manageDeptName) {
        if (manageDeptName == null) {
            throw new InvalidParameterException();
        }

        this.manageDeptName = manageDeptName;
    }

    public void addStaffAppointHandler(StaffAppointHandler handler) {
        this.staffAppoint = handler;
    }

    public void onStaffAppoint(Staff member, double newStaffMemberSalary) {
        if (staffAppoint != null) {
            StaffAppointEventArgs event = new StaffAppointEventArgs(member, newStaffMemberSalary);
            staffAppoint.addStaff(event);
        }
    }

    @Override
    public String toString() {
        return String.format("%s, manageDeptName: %s", super.toString(), manageDeptName);
    }
}
