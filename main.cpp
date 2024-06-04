/*
Ronald Johnson
Mon Feb 12, 2024
Program Description

This program is designed to use a random number generator 
to select a muscle group from an array of options and then 
provide four different movements to target that specific 
muscle group. For example, if the random number generator 
selects "Chest day," there are four sections of the chest 
muscle to consider: upper, lower, middle, and center. Each 
section should have a different movement to target that 
specific area. The program should also determine the weight, 
reps, sets, and whether it's a super set, drop set, or a 
standard workout day. At the end, there is a 50/50 chance 
of being instructed to do either cardio or stretching. If 
the program instructs to do cardio, it will randomly select 
between 5-10 minutes of activities such as punching bag, 
biking, running, or using the sauna, followed by a 
requirement to do stretching. However, if it only instructs 
to do stretching, then the program ends at that point. 

it should look like this

[RUN]

MGOTD (Muscle Group Of The Day)
---------|------|----|----|------------------------
workout 1|weight|reps|sets|drop/super/PR/none
---------|------|----|----|------------------------
workout 2|weight|reps|sets|drop/super/PR/none
---------|------|----|----|------------------------
workout 3|weight|reps|sets|drop/super/PR/none
---------|------|----|----|------------------------
workout 4|weight|reps|sets|drop/super/PR/none
---------|------|----|----|------------------------
Cardio/Stretch   |x minutes| 

*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>  // For rand and srand
#include <ctime>    // For time
#include <vector>
#include <set>

using namespace std;

int main() {
  

    string MGOTD[] = {"Chest", "Shoulders", "Back", "Arms", "Abs", "Legs"};

    string exercises[6][30] = {
        //chest
        { "Barbell Bench", "Chest dips", "Dumbbell fly", "Chest press machine", "Flat db press", "Seated cable fly", "Pec dec machine", "weighted push-ups", "Incline bench press", "Decline DB press", "Pinch press", "Pushups", "Cable flys", "Decline bench", "Incline pinch press", "Wide grip bench press", "Overhead squat", "Weighted dips", "Muscle ups", "Seesaw DB chest press", "Push press", "Plank to pushups", "Power clean", "Hang clean", "Power punch on bag", "5 punch combo on bag", "Hip thrust to DB press", "DB floor press", "DB shadowboxing", "DB punch the ceiling" },
        //shoulders  
        { "Lateral raise", "Arnold press", "Cable rear flyer", "Rear delt fly", "Overhead press", "Upright row", "Barbell shrug", "Face pull", "Lying reverse fly", "One arm db swing", "Cable shoulder press", "Front raise", "Military press", "Seated barbell press", "Cable high row", "Pull ups", "Handstand pushups", "Wallball throws", "Man maker exercise", "Rotator cuff external/internal", "Kettlebell clean", "Kettlebell press", "Turkish get up", "Handle up goblet squat", "DB z press", "Kneeling landmine press", "Seated Arnold press", "Landmine punch", "Landmine twist", "Lightweight DB flies 3mins" },
        //back  
        { "Barbell row", "Cable face pull", "Dumbbell shrug", "Landmine row", "Seal row", "Deadlift", "Chainsaw row", "Good mornings", "Pndlay row", "Lat pulldown", "Dumbbell row", "Inverted row", "Behind the neck lat pulldown", "Rope pull", "Wide pull-ups", "cable lat pullover", "Reverse grip lat pulldown", "Farmer carries", "Burpees", "Pull-ups", "Assisted pull-ups", "Weighted pull-ups", "Barbell dead row", "Seated cable decline row", "DB high pull", "Kneeling one arm lat pulldown", "Cross body kneeling lat pulldown", "Wide grip cable row", "DB lat pullover", "Chest supported Row" },
        //arms  
        { "Lying tricep extension", "Tricep extension", "Skull crushers", "Cable pushdowns", "Bicep curls straight bar", "Dumbbell curls", "DB short head curls", "Single arm DB overhead extension", "DB preacher curls", "Reverse curl", "Farmer carries", "Pinch carries", "Dead hang", "Zottoman curl", "Bottoms up kettlebell hold", "Reverse wrist curl", "Pull-ups assisted", "Pull-ups weighted", "Chin ups", "Overhead cable bicep curl", "Weighted shadowboxing ", "Reverse grip lat pulldown", "Wrist curl", "Rice bucket training", "Hammer curl", "Fat grip curl", "Wrist roller ", "Power punch the bag", "Knuckle push-ups", "Cable lat pullover" },
        //abs  
        { "Hanging knee raises", "Mtn clmbr cross", "Bent knee twist", "obliqe crunches", "Twisting crunch", "Rocking plank", "Hip raise", "Reverse crunch", "Weighted crunch", "Russian twist", "Rope crunches", "oblique crunch stand", "Turkish get up", "Ab wheel", "Decline reverse crunch", "Butterfly kicks", "Dragon flag", "Plank ", "Cable twist", "Roman chair", "Kneeling cable twist", "Eccentric power up", "Hanging knee twist", "Russian twist press", "Dumbell drag", "Knee tuck", "Side plank", "farmer carries", "Swipers", "Gymnast ab tuck" },
        //legs  
        { "Barbell squat", "Weighted lunges", "High kick on punch bag", "Wall balls", "Roman deadlift", "Goblet squat", "Smith machine calf raises", "Backwards sled pulls", "Pistol squat", "Leg extension", "Hamstring curls", "Goblet smith squat", "Shin curls", "Hip thrust", "Leg press", "Leg abduct + adduct", "Front squat", "Split squat", "Elevated heel squat", "Bulgarian split squat", "Hack squat", "DB step ups", "Bike machine heavy resistance", "Sled push", "DB Spanish squat", "Hyperextension ", "Nordic hamstring curl", "Lying hamstring curl", "goodmornings", "Glute kickbacks "}
    };

    int current_index = 0;

    // Generate a seed for the random number generator
    srand(time(0));



 
    // Read the current index from a file
    ifstream index_file("current_index.txt");
    if (index_file.is_open()) {
        index_file >> current_index;
        index_file.close();
    }

    // Print the element at the current index
    cout << "\n          MGOTD:    | " << MGOTD[current_index] << endl;
    cout << "--------------------|-----|----|----|------------------------" << endl;

// Set to store selected exercises
    set<string> selected_exercises;

    // Output four random exercises based on the selected workout type
    for (int i = 0; i < 4; i++) {
        int random_exercise_index;
        do {
            random_exercise_index = rand() % 16;  // There are 16 exercises for each workout type
        } while (selected_exercises.count(exercises[current_index][random_exercise_index]) > 0); // Check if the exercise is already selected
        selected_exercises.insert(exercises[current_index][random_exercise_index]); // Insert the selected exercise
        cout << exercises[current_index][random_exercise_index] << endl;
        cout << "--------------------|-----|----|----|------------------------" << endl;
    }
    cout << "Cardio/Stretch   " << rand() % 10 + 5 << " minutes\n" << endl;

    // Update the current index for the next run
    current_index = (current_index + 1) % 6;  // There are 6 workout types

    // Write the updated current index back to the file
    ofstream new_index_file("current_index.txt");
    if (new_index_file.is_open()) {
        new_index_file << current_index;
        new_index_file.close();
    }

    return 0;
}


