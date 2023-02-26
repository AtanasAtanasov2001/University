module com.gui {
    requires javafx.controls;
    requires javafx.fxml;
    requires com.model;

    opens com.gui to javafx.fxml;
    exports com.gui;
}