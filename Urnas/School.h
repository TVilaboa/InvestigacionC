

struct school
{
    int code;
    int cantboxes;
};

void createSchool(struct school *school,int code,int cant)
{
    school->cantboxes=cant;
    school->code=code;
}

