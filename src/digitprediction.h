#ifndef DIGITPREDICTION_H
#define DIGITPREDICTION_H

#undef slots
#include <torch/torch.h>
#include "torch/script.h"
#include <memory>
#define slots Q_SLOTS

#include <string.h>
#include <QImage>

class DigitPrediction
{
public:
    DigitPrediction(std::string modelPath);
    void predict(QImage image);
    int digit;
    float prob;

private:
    torch::jit::script::Module model;
    torch::Device device = at::kCPU;
};

#endif // DIGITPREDICTION_H
