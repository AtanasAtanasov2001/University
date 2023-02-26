package com.test;

import com.model.HRdepartment;
import com.model.Manager;
import com.model.Staff;
import com.model.StaffAppointHandler;

import java.util.Arrays;

public class AppointTest {
    public static void main(String[] args) {
        Manager boss = new Manager("Manager", 2000, "Invoices");
        Staff[] candidates = new Staff[]{
                new Staff("Staff 1", 1000, "Department 1"),
                new Staff("Staff 2", 1100, "Department 2")
        };

        System.out.printf("Manager: %s\n",boss);
        System.out.printf("Candidates: %s\n", Arrays.toString(candidates));

        HRdepartment hRdepartment = new HRdepartment(boss);

        StaffAppointHandler sah = hRdepartment.getAppointHandler();
        boss.addStaffAppointHandler(sah);

        boss.onStaffAppoint(candidates[0], 1300);
        boss.onStaffAppoint(candidates[1], 1500);

        System.out.println(sah);
        System.out.printf("Candidates: %s\n", Arrays.toString(candidates));
    }
}
