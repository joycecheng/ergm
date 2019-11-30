/*  File src/init.c in package ergm, part of the Statnet suite
 *  of packages for network analysis, https://statnet.org .
 *
 *  This software is distributed under the GPL-3 license.  It is free,
 *  open source, and has the attribution requirements (GPL Section 7) at
 *  https://statnet.org/attribution
 *
 *  Copyright 2003-2019 Statnet Commons
 */
/* This code was procedurally generated by running

   > tools::package_native_routine_registration_skeleton(".", "./src/init.c")

   in R started in the package's root directory, then changing

   "R_useDynamicSymbols(dll, FALSE)" to "R_useDynamicSymbols(dll, TRUE)".
*/

#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* .C calls */
extern void AllStatistics(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
extern void CD_wrapper(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
extern void full_geodesic_distribution(void *, void *, void *, void *, void *, void *, void *, void *);
extern void geodesic_matrix(void *, void *, void *, void *, void *, void *, void *);
extern void Godfather_wrapper(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
extern void MCMCPhase12(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
extern void MPLE_wrapper(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
extern void network_stats_wrapper(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
extern void node_geodesics(void *, void *, void *, void *, void *, void *, void *, void *);
extern void pair_geodesic(void *, void *, void *, void *, void *, void *, void *, void *, void *);
extern void SAN_wrapper(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
extern void wt_network_stats_wrapper(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
extern void WtCD_wrapper(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
extern void WtGodfather_wrapper(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
extern void WtSAN_wrapper(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);

/* .Call calls */
extern SEXP get_ergm_omp_terms();
extern SEXP MCMC_wrapper(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP set_ergm_omp_terms(SEXP);
extern SEXP WtMCMC_wrapper(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);

static const R_CMethodDef CEntries[] = {
    {"AllStatistics",              (DL_FUNC) &AllStatistics,              13},
    {"CD_wrapper",                 (DL_FUNC) &CD_wrapper,                 25},
    {"full_geodesic_distribution", (DL_FUNC) &full_geodesic_distribution,  8},
    {"geodesic_matrix",            (DL_FUNC) &geodesic_matrix,             7},
    {"Godfather_wrapper",          (DL_FUNC) &Godfather_wrapper,          20},
    {"MCMCPhase12",                (DL_FUNC) &MCMCPhase12,                35},
    {"MPLE_wrapper",               (DL_FUNC) &MPLE_wrapper,               16},
    {"network_stats_wrapper",      (DL_FUNC) &network_stats_wrapper,      14},
    {"node_geodesics",             (DL_FUNC) &node_geodesics,              8},
    {"pair_geodesic",              (DL_FUNC) &pair_geodesic,               9},
    {"SAN_wrapper",                (DL_FUNC) &SAN_wrapper,                35},
    {"wt_network_stats_wrapper",   (DL_FUNC) &wt_network_stats_wrapper,   15},
    {"WtCD_wrapper",               (DL_FUNC) &WtCD_wrapper,               19},
    {"WtGodfather_wrapper",        (DL_FUNC) &WtGodfather_wrapper,        22},
    {"WtSAN_wrapper",              (DL_FUNC) &WtSAN_wrapper,              30},
    {NULL, NULL, 0}
};

static const R_CallMethodDef CallEntries[] = {
    {"get_ergm_omp_terms", (DL_FUNC) &get_ergm_omp_terms,  0},
    {"MCMC_wrapper",       (DL_FUNC) &MCMC_wrapper,       25},
    {"set_ergm_omp_terms", (DL_FUNC) &set_ergm_omp_terms,  1},
    {"WtMCMC_wrapper",     (DL_FUNC) &WtMCMC_wrapper,     19},
    {NULL, NULL, 0}
};

void R_init_ergm(DllInfo *dll)
{
    R_registerRoutines(dll, CEntries, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, TRUE);
}
