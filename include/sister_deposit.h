#ifndef GUARD_SISTER_DEPOSIT_H
#define GUARD_SISTER_DEPOSIT_H

u32 GetSavings(void);
void SetSavings(u32 amount);
u32 CalcAmountToSave(u32 money);
u32 DepositInSisterSavings(void);
bool32 IsSavingMoney(void);
void CreateWithdrawalWindow(void);
void WithdrawSavings(void);

#endif // GUARD_SISTER_DEPOSIT_H
