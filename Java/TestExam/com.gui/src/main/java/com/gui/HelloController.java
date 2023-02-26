package com.gui;

import java.net.URL;
import java.util.Arrays;
import java.util.Random;
import java.util.ResourceBundle;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

import com.model.HRdepartment;
import com.model.Manager;
import com.model.Staff;
import com.model.StaffAppointHandler;
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextInputDialog;

public class HelloController {

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private Button btnAppoint;

    @FXML
    private Button btnGenerate;

    @FXML
    private Button btnQuit;

    @FXML
    private TextArea txaResult;

    private Manager boss;
    private Staff[] candidates;
    private Random random;
    private TextInputDialog staffNameDialog;
    private TextInputDialog newSalaryDialog;
    private HRdepartment hRdepartment;

    @FXML
    void btnAppointOnAction(ActionEvent event) {
        String staffName = staffNameDialog.showAndWait().get();
        double newSalary = Double.parseDouble(newSalaryDialog.showAndWait().get());

        Staff staff = Arrays.stream(candidates)
                .filter(candidate -> candidate.getName().equals(staffName))
                .findFirst().get();

        boss.onStaffAppoint(staff, newSalary);

        txaResult.appendText(String.format("\n%s", hRdepartment));
    }

    // Map<String, Integer> map = new HashMap<>();
    // map.entrySet()
    //    .stream()
    //    .sorted(Map.Entry.comparingByValue())
    //    .collect(Collectors.toSet());

    @FXML
    void btnGenerateOnAction(ActionEvent event) {
        // 10 candidates, salary [1000, 1500], use StreamAPI.
        candidates = IntStream
                .rangeClosed(1, 10)
                .mapToObj(i -> new Staff(String.format("Staff %d", i),
                        random.nextInt(1000, 1500) + random.nextDouble(),
                        String.format("Department %d", i)))
                .toArray(Staff[]::new);

//        String candidatesText = Arrays.stream(candidates)
//                .map(Staff::toString)
//                .collect(Collectors.joining("\n"));

        String candidatesText = Arrays.stream(candidates)
                .map(Staff::toString)
                .reduce("", (accumulator, staffName) -> accumulator += staffName + "\n");

        txaResult.appendText(String.format("Manager: %s\nCandidates:\n%s\n", boss, candidatesText));
    }

    @FXML
    void btnQuitOnAction(ActionEvent event) {
        Platform.exit();
    }

    @FXML
    void initialize() {
        assert btnAppoint != null : "fx:id=\"btnAppoint\" was not injected: check your FXML file 'hello-view.fxml'.";
        assert btnGenerate != null : "fx:id=\"btnGenerate\" was not injected: check your FXML file 'hello-view.fxml'.";
        assert btnQuit != null : "fx:id=\"btnQuit\" was not injected: check your FXML file 'hello-view.fxml'.";
        assert txaResult != null : "fx:id=\"txaResult\" was not injected: check your FXML file 'hello-view.fxml'.";

        boss = new Manager("Manager", 2000, "Invoices");
        random = new Random();

        staffNameDialog = new TextInputDialog();
        staffNameDialog.setTitle("Prompt");
        staffNameDialog.setHeaderText(null);
        staffNameDialog.setContentText("Pick candidate name");

        newSalaryDialog = new TextInputDialog();
        newSalaryDialog.setTitle("Prompt");
        newSalaryDialog.setHeaderText(null);
        newSalaryDialog.setContentText("Enter new salary");

        hRdepartment = new HRdepartment(boss);

        StaffAppointHandler sah = hRdepartment.getAppointHandler();

        boss.addStaffAppointHandler(sah);
    }

}
