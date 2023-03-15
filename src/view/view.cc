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