
class box{
    bool is_snak;
    bool is_ladar;
    int snak_end;
    int ladar_end;
public:
    box(int snak, int ladar)
    {
        is_snak = 0;
        is_ladar = 0;

        snak_end= snak;
        ladar_end = ladar;
    }

    void set_snak(int end)
    {
        is_snak = 1;
        is_ladar =0;
        snak_end = end;
    }
    void set_ladar(int end)
    {
        is_ladar =1;
        is_snak =0;
        ladar_end = end;
    }
    bool snak()
    {
        return is_snak;
    }
    bool ladar()
    {
        return is_ladar;
    }
    int snak_pos()
    {
        return snak_end;
    }
    int lader_pos()
    {
        return ladar_end;
    }
};
