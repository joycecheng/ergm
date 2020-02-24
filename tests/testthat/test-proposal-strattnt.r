#  File tests/testthat/test-proposal-strattnt.R in package ergm, part of the Statnet suite
#  of packages for network analysis, https://statnet.org .
#
#  This software is distributed under the GPL-3 license.  It is free,
#  open source, and has the attribution requirements (GPL Section 7) at
#  https://statnet.org/attribution
#
#  Copyright 2003-2019 Statnet Commons
#######################################################################

context("test-proposal-strattnt.R")

test_that("StratTNT works with undirected unipartite networks", {
  nw <- network.initialize(1000, dir=FALSE)

  nw %v% "race" <- c(rep("A", 20), rep("B", 20), rep("W",960))

  pmat <- matrix(1,3,3)
  diag(pmat) <- c(2,2,30)

  target.stats <- c(1000, 50, 50, 800)
  nws <- san(nw ~ edges + nodematch("race",levels=NULL, diff=TRUE), target.stats = target.stats, control=control.san(SAN.nsteps=4e4, SAN.prop.args = list(pmat=pmat, attr="race")), constraints="StratTNT"~.)
  sr <- summary(nws ~ edges + nodematch("race",levels=NULL, diff=TRUE))  
  
  expect_true(all(abs(sr - target.stats) <= 0.05*target.stats))
  
  # to test initialization code, redo the SAN run with different targets, starting from the previous network
  pmat <- matrix(10,3,3)
  diag(pmat) <- c(7,7,20)

  target.stats <- c(1000, 125, 125, 350)
  nws2 <- san(nws ~ edges + nodematch("race",levels=NULL, diff=TRUE), target.stats = target.stats, control=control.san(SAN.nsteps=8e4, SAN.prop.args = list(pmat=pmat, attr="race")), constraints="StratTNT"~.)
  sr <- summary(nws2 ~ edges + nodematch("race",levels=NULL, diff=TRUE))
  
  expect_true(all(abs(sr - target.stats) <= 0.05*target.stats))
})


test_that("StratTNT works with directed networks", {
  nw <- network.initialize(1000, dir=TRUE)

  nw %v% "race" <- c(rep("A", 20), rep("B", 20), rep("W",960))

  pmat <- matrix(c(100, 350, 0, 10, 100, 0, 100, 0, 840),3,3,byrow=TRUE)

  target.stats <- c(100, 10, 100, 350, 100, 0, 0, 0, 840)
  nws <- san(nw ~ nodemix("race"), target.stats = target.stats, control=control.san(SAN.nsteps=2e5, SAN.prop.args = list(pmat=pmat, attr="race")), constraints="StratTNT"~.)
  sr <- summary(nws ~ nodemix("race"))
  
  expect_true(all(abs(sr - target.stats) <= 0.05*target.stats))

  # redo with different targets, starting from previous network
  pmat2 <- matrix(c(50, 50, 350, 50, 50, 100, 50, 400, 400),3,3,byrow=TRUE)

  pmat3 <- (pmat + pmat2)/2

  target.stats <- c(pmat2)
  nws2 <- san(nws ~ nodemix("race"), target.stats = target.stats, control=control.san(SAN.nsteps=2e5, SAN.prop.args = list(pmat=pmat3, attr="race")), constraints="StratTNT"~.)
  sr <- summary(nws2 ~ nodemix("race"))
  
  expect_true(all(abs(sr - target.stats) <= 0.05*target.stats))
})

test_that("StratTNT works with bipartite networks", {
  nw <- network.initialize(900, bip = 100, dir=FALSE)

  nw %v% "race" <- c(rep("B", 20), rep("W", 60), rep("A", 40), rep("B", 20), rep("W",860))

  pmat <- matrix(c(0, 100, 2, 2, 0, 2, 100, 100, 0),3,3,byrow=TRUE)

  target.stats <- c(0, 2, 100, 100, 0, 100, 2, 2, 0)
  nws <- san(nw ~ nodemix("race"), target.stats = target.stats, control=control.san(SAN.nsteps=2e5, SAN.prop.args = list(pmat=pmat, attr="race")), constraints="StratTNT"~.)
  sr <- summary(nws ~ nodemix("race"))

  expect_true(all(abs(sr - target.stats) <= 0.05*target.stats))
  
  # redo with different targets, starting from previous network
  pmat2 <- matrix(c(100, 10, 0, 0, 100, 100, 10, 10, 0),3,3,byrow=TRUE)

  pmat3 <- (pmat + pmat2)/2

  target.stats <- c(pmat2)  
  nws2 <- san(nws ~ nodemix("race"), target.stats = target.stats, control=control.san(SAN.nsteps=2e5, SAN.prop.args = list(pmat=pmat3, attr="race")), constraints="StratTNT"~.)
  sr <- summary(nws2 ~ nodemix("race"))

  expect_true(all(abs(sr - target.stats) <= 0.05*target.stats))
})
