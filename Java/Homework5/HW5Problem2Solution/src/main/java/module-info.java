module com.example.hw5problem2solution {
    requires com.example.hw5problem2;
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.hw5problem2solution to javafx.fxml;
    exports com.example.hw5problem2solution;
}