package com.model;

public class Staff extends Employee {

    private String workAt;

    public Staff(String name, double salary, String workAt) {
        super(name, salary);
        setWorkAt(workAt);
    }

    public String getWorkAt() {
        return workAt;
    }

    public void setWorkAt(String workAt) {
        this.workAt = workAt != null ? workAt : "Candidate";
    }

    @Override
    public String toString() {
        return String.format("%s, workAt: %s", super.toString(), workAt);
    }
}
