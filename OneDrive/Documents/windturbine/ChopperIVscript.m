
PhaseVoltage=[];
ChargingCurrent=[];

for x = 1:16
    V=(x-1)*2.5;
    scopeConfig = get_param('WindTurbineCircuit/Scope','ScopeConfiguration');
    scopeConfig.DataLogging = true;
    scopeConfig.DataLoggingSaveFormat = 'Dataset';
    out= sim('WindTurbineCircuit');
    Current = out.ScopeData{1}.Values.Data(:,1);
    ChargingCurrent(x)=Current(end);
    PhaseVoltage(x)=V;
end

figure
plot(PhaseVoltage,ChargingCurrent);
title("IV")
grid;
