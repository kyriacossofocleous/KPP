int InitSaveData();
int InitSaveError();
int InitSaveE();
void Initialize();
int SaveData();
int CloseSaveData();
int CloseSaveError();
int CloseSaveE();
int GenerateMatlab(char *prefix);
void GetMass(KPP_REAL CL[], KPP_REAL Mass[]);
void INTEGRATE(double TIN, double TOUT);
double Stopwatch(double t);

int main()
{
  KPP_REAL dval[NSPEC];
  int i;
  double t;
  /* ---- TIME VARIABLES ------------------ */

  RTOLS = 1e-3;
  TSTART = 3600 * 12;
  TEND = TSTART + 3600 * 24 * 5;
  DT = 3600.;
  TEMP = 236.21;

  t = Stopwatch(0);
  // for (int j = 0; j < 10000; j++)
  // {
    Initialize();
    for (i = 0; i < NVAR; i++)
    {
      RTOL[i] = RTOLS;
      ATOL[i] = 1.0;
    }
    STEPMIN = 0.01;
    STEPMAX = 900;

    /* ********** TIME LOOP **************************** */

    InitSaveData();
    InitSaveError();
    InitSaveE();

    printf("\n%7s %7s   ", "done[%]", "Time[h]");
    for (i = 0; i < NMONITOR; i++)
      printf("%8s  ", SPC_NAMES[MONITOR[i]]);
    for (i = 0; i < NMASS; i++)
      printf("(%6s)  ", SMASS[i]);

    TIME = TSTART;
    FUNTIME = (double)TSTART;
    while (TIME <= TEND)
    {
      GetMass(C, dval);
      printf("\n%6.1f%% %7.2f   ", (TIME - TSTART) / (TEND - TSTART) * 100, TIME / 3600);
      for (i = 0; i < NMONITOR; i++)
        printf("%9.3e  ", C[MONITOR[i]] / CFACTOR);
      for (i = 0; i < NMASS; i++)
        printf("%9.3e  ", dval[i] / CFACTOR);

      SaveData();

      INTEGRATE(TIME, TIME + DT);
      TIME += DT;
      FUNTIME += (double)DT;
    }

    /* *********** END TIME LOOP *********************** */
  // }
  t = Stopwatch(t);
  printf("Simulation Time: %10.6f", t);
  printf("\n");
  CloseSaveData();
  CloseSaveError();
  CloseSaveE();

  return 0; /*didnt return anything initially */
}
