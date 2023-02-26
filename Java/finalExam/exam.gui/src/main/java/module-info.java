module com.example.exam_gui {
    requires javafx.controls;
    requires javafx.fxml;
    requires exam.logic;

    opens com.example.exam_gui to javafx.fxml;
    exports com.example.exam_gui;
}