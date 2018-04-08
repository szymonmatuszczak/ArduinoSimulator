void onUpdate()
{
    for(vector<Pin>::iterator it=SIM_DEVICE.begin();it!=SIM_DEVICE.end();it++)
    {
        cout  << "Digital pin " << it-SIM_DEVICE.begin() << " (PORT" << it->getPortName() << +it->portPin << ") | "
            << it->getMode() << " | " << it->getValue() << endl;
    }
    cout << endl << endl;
}