/***************************************************************************
LibBandit - Multi-Armed Bandit Library
Written in 2015 by Tor Lattimore tor.lattimore@gmail.com

To the extent possible under law, the author(s) have dedicated all 
copyright and related and neighboring rights to this software to the 
public domain worldwide. This software is distributed without any warranty.

You should have received a copy of the CC0 Public Domain Dedication 
along with this software. If not, 
see http://creativecommons.org/publicdomain/zero/1.0/
***************************************************************************/


/************************************************************
The Gaussian bandit implementation of a bandit problem. 

Rewards are Gaussian with given means and unit variance.

[TODO] Genearlise to arbitrary variance.
************************************************************/
#pragma once

#include <cstdint>
#include <vector>
#include <random>
#include <functional>
#include <string>

#include "bandit.h"


class GaussianBandit : public BanditProblem {
  public:
  
  GaussianBandit(std::vector<double> means, std::default_random_engine &g) : gen(g) {
    this->K = means.size();
    this->means = means;
    setup();
  }

  double sample(int i) {
    std::normal_distribution<double> dist(means[i], 1.0);
    return dist(gen);
  }

  double mean(int i)const {
    return means[i];
  }


  private:
  std::default_random_engine &gen;
  std::vector<double> means;
};


