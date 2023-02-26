package com.model;

import java.security.InvalidParameterException;
import java.util.ArrayList;

public class HRdepartment {
    private Manager manager;
    private ArrayList<Staff> staff;

    public HRdepartment(Manager manager) {
        setManager(manager);
        staff = new ArrayList<>();
    }

    public Manager getManager() {
        return new Manager(manager.getName(), manager.getSalary(), manager.getManageDeptName());
    }

    public void setManager(Manager manager) {
        if (manager == null) {
            throw new InvalidParameterException();
        }

        this.manager = new Manager(manager.getName(), manager.getSalary(), manager.getManageDeptName());
    }

    private class StaffAppointHandlerInternal implements StaffAppointHandler {

        private String appointDepartment;

        public StaffAppointHandlerInternal(String appointDepartment) {
            setAppointDepartment(appointDepartment);
        }

        public String getAppointDepartment() {
            return appointDepartment;
        }

        public void setAppointDepartment(String appointDepartment) {
            if (appointDepartment == null) {
                throw new InvalidParameterException();
            }

            this.appointDepartment = appointDepartment;
        }

        @Override
        public void addStaff(StaffAppointEventArgs event) {
            Staff newStaff = event.getNewStaff();
            newStaff.setWorkAt(appointDepartment);
            newStaff.setSalary(event.getNewSalary());
            staff.add(newStaff);
        }

        @Override
        public String toString() {
            return String.format("%s\nappointDepartment: %s", HRdepartment.this.toString(), appointDepartment);
        }
    }

    public StaffAppointHandler getAppointHandler() {
        return new StaffAppointHandlerInternal(manager.getManageDeptName());
    }

    @Override
    public String toString() {
        return String.format("Manager: %s\nStaff: %s", manager, staff);
    }
}
