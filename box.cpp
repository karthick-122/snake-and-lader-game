
class box{
    bool is_snak;
    bool is_ladar;
    int snak_end;
    int ladar_end;
    bool is_snake_end;
    bool is_ladar_end;
public:
    box(int snak, int ladar);
    void set_snak(int end);
    void set_ladar(int end);
    bool snak();
     bool ladar();
     int snak_pos();
     int lader_pos();
     void set_snake_end();
     void set_lader_end();
     bool get_snake_end();
     bool get_lader_end();




};

void box:: set_lader_end()
{
    is_snake_end=1;
}
void box:: set_snake_end()
{
    is_snake_end=1;
}

bool box:: get_lader_end()
{
    return is_ladar_end;
}
bool box:: get_snake_end()
{
    return is_snake_end;
}
box::box(int snak, int ladar)
    {
        is_snak = 0;
        is_ladar = 0;
        is_snake_end=0;
        is_ladar_end=0;

        snak_end= snak;
        ladar_end = ladar;
    
    }

    void box:: set_snak(int end)
    {
        is_snak = 1;
        is_ladar =0;
        snak_end = end;
    }
    void box::set_ladar(int end)
    {
        is_ladar =1;
        is_snak =0;
        ladar_end = end;
    }
    bool box::snak()
    {
        return is_snak;
    }
    bool box:: ladar()
    {
        return is_ladar;
    }
    int box:: snak_pos()
    {
        return snak_end;
    }
    int box:: lader_pos()
    {
        return ladar_end;
    }