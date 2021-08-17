#include <torch/script.h>
#include <iostream>
#include <QApplication>
#include "mainwindow.h"
#include "digitprediction.h"

int main(int argc, const char* argv1[], char* argv2[]) {
  if (argc != 2) {
    std::cerr << "usage: example-app <path-to-exported-script-module>\n";
    return -1;
  }

//  DigitPrediction a = DigitPrediction(argv1[1]);
  // Create a vector of inputs.
//  std::vector<torch::jit::IValue> inputs;
//  inputs.push_back(torch::ones({1, 1, 32, 32}).to(at::kCUDA));

  // Execute the model and turn its output into a tensor.
//  at::Tensor output = model.forward(inputs).toTensor();
//  std::cout << output.slice(/*dim=*/1, /*start=*/0, /*end=*/10) << '\n';
//  std::cout << output.argmax(1).item<int>() << '\n';

  QApplication app(argc, argv2);
  MainWindow window;
  window.setClassifier(argv1[1]);
  window.show();
  return app.exec();
}
