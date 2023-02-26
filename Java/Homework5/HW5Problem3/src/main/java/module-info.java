module com.example.hw5problem3 {
    requires javafx.controls;
    requires javafx.fxml;


    opens Hw5Problem3 to javafx.fxml;
    exports Hw5Problem3;
}