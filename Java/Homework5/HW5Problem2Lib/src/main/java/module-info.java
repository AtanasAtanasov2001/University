module com.example.hw5problem2 {
    requires javafx.controls;
    requires javafx.fxml;

    opens com.example.hw5problem2 to javafx.fxml;
    exports com.example.hw5problem2;
}