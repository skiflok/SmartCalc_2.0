//
// Created by Violator Emilie on 3/15/23.
//

void MainWindow::on_calcculate_clicked() {

  double res = 0;

  QString inputStr = ui->text_label->text();

  try {
	res =  controller->Calculation(inputStr);
	inputStr = QString::number(res, 'g', 15);
	ui->text_label->setText(inputStr);
  } catch (...) {
	ui->text_label->setText("invalid input");
  }

}


void MainWindow::on_plot_clicked() {

  ui->widget->clearGraphs();
  h = ui->lineEdit_step->text().toDouble();

  DataPlot data_plot_input(ui->text_label->text().toStdString(),
                           ui->lineEdit_x_min->text().toDouble(),
                           ui->lineEdit_x_max->text().toDouble() + h);
  std::pair<QVector<double>, QVector<double>> data_plot;

  ui->widget->xAxis->setRange(data_plot_input.x_begin_, data_plot_input.x_end_);
  ui->widget->yAxis->setRange(ui->lineEdit_y_min->text().toDouble(), ui->lineEdit_y_max->text().toDouble());
  try {
    data_plot = controller->PlotCalculation(data_plot_input);
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(data_plot.first, data_plot.second);
    ui->widget->replot();
  } catch (...) {
    ui->text_label->setText("invalid parametr");
  }

  ////  N = (xEnd - xBegin) / h + 2;

}

