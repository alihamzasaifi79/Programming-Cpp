#include<iostream>
#include<string>
using namespace std;

struct professor {
    string name,subject;
};

struct student {
    string name;
    float grade;
};

struct course {
    string title;
    professor* prof;
    student* students;
    int student_count;
};

struct university {
    course* courses;
    int course_count;
};

void add_course(university& uni) {
    string title, prof_name, subject;
    int student_count;
    
    cout<<"enter course title:";
    cin>>title;
    cout<<"enter professor name:";
    cin>>prof_name;
    cout<<"enter subject:";
    cin>>subject;
    cout<<"enter number of students:";
    cin>>student_count;
    
    course* temp=new course[uni.course_count+1];
    for(int i=0;i<uni.course_count;i++) temp[i]=uni.courses[i];
    delete[] uni.courses;
    uni.courses=temp;
    
    uni.courses[uni.course_count].title=title;
    uni.courses[uni.course_count].prof=new professor{prof_name,subject};
    uni.courses[uni.course_count].students=new student[student_count];
    uni.courses[uni.course_count].student_count=student_count;
    uni.course_count++;
}

void enroll_student(course& crs) {
    string name;
    float grade;
    
    cout<<"enter student name:";
    cin>>name;
    cout<<"enter student grade:";
    cin>>grade;
    
    student* temp=new student[crs.student_count+1];
    for(int i=0;i<crs.student_count;i++) temp[i]=crs.students[i];
    delete[] crs.students;
    crs.students=temp;
    crs.students[crs.student_count++]={name,grade};
}

void display(const university& uni) {
    for(int i=0;i<uni.course_count;i++) {
        cout<<"course:"<<uni.courses[i].title<<"|professor:"<<uni.courses[i].prof->name<<"\n";
        for(int j=0;j<uni.courses[i].student_count;j++)
            cout<<"  student:"<<uni.courses[i].students[j].name<<"|grade:"<<uni.courses[i].students[j].grade<<"\n";
    }
}

void update_grade(course& crs) {
    string name;
    float grade;
    
    cout<<"enter student name to update grade:";
    cin>>name;
    cout<<"enter new grade:";
    cin>>grade;
    
    for(int i=0;i<crs.student_count;i++)
        if(crs.students[i].name==name)
            crs.students[i].grade=grade;
}

void remove_student(course& crs) {
    string name;
    
    cout<<"Enter student name to remove:";
    cin>>name;
    
    int index=-1;
    for(int i=0;i<crs.student_count;i++)
        if(crs.students[i].name==name) index=i;
    if(index==-1) return;
    for(int i=index;i<crs.student_count-1;i++)
        crs.students[i]=crs.students[i+1];
    crs.student_count--;
}

void cleanup(university& uni) {
    for(int i=0;i<uni.course_count;i++) {
        delete uni.courses[i].prof;
        delete[] uni.courses[i].students;
    }
    delete[] uni.courses;
}

int main() {
    university uni={nullptr,0};
    int choice;
    
    do {
        cout<<"\n1. add course\n2. enroll student\n3. display\n4. update grade\n5. remove student\n6. exit\nenter choice:";
        cin>>choice;
        
        switch(choice) {
            case 1:
                add_course(uni);
                break;
            case 2:
                if(uni.course_count>0)
                    enroll_student(uni.courses[0]);
                else
                    cout<<"no courses available. add a course first.\n";
                break;
            case 3:
                display(uni);
                break;
            case 4:
                if(uni.course_count>0)
                    update_grade(uni.courses[0]);
                else
                    cout<<"no courses available. add a course first.\n";
                break;
            case 5:
                if(uni.course_count>0)
                    remove_student(uni.courses[0]);
                else
                    cout<<"no courses available. add a course first.\n";
                break;
            case 6:
                cleanup(uni);
                cout<<"exiting...\n";
                break;
            default:
                cout<<"invalid choice. try again.\n";
        }
    } while(choice!=6);
}

