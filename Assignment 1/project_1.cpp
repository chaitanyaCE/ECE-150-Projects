# include <iostream>
# include <cmath>

int main () {
       
    // FINAL EXAM
    double max_final;
    std::cout << "Enter the maximum grade on the final examination:  "  ;
    std::cin >> max_final;
    while (max_final != std::round(max_final) || max_final <= 0) {
        std::cout << "Enter the maximum grade on the final examination:  " ;
        std::cin >> max_final;
    }

    double user_final;
    std::cout << "Enter your grade on the final examination: "  ;
    std::cin >> user_final;
    while (user_final < 0 || user_final > max_final) {
        std::cout << "Enter your grade on the final examination: " ;
        std::cin >> user_final;
    }

    // MID-TERM EXAM

    double max_term;
    std::cout << "Enter the maximum grade on the mid-term examination:  "  ;
    std::cin >> max_term;
    while (max_term != std::round(max_term) || max_term <= 0) {
        std::cout << "Enter the maximum grade on the mid-term examination:  " ;
        std::cin >> max_term;
    }

    double user_term;
    std::cout << "Enter your grade on the mid-term examination: "  ;
    std::cin >> user_term;
    while (user_term < 0 || user_term > max_term) {
        std::cout << "Enter your grade on the mid-term examination: " ;
        std::cin >> user_term;
    }

    // PROJECT 1
        
    double max_p1;
    std::cout << "Enter the maximum grade on project 1:  "  ;
    std::cin >> max_p1;
    while (max_p1 != std::round(max_p1) || max_p1 <= 0) {
        std::cout << "Enter the maximum grade on project 1:  " ;
        std::cin >> max_p1;
    }

    double user_p1;
    std::cout << "Enter your grade on project 1: "  ;
    std::cin >> user_p1;
    while (user_p1 < 0 || user_p1 > max_p1) {
        std::cout << "Enter your grade on project 1: " ;
        std::cin >> user_p1;
    }
    
    // PROJECT 2
        
    double max_p2;
    std::cout << "Enter the maximum grade on project 2:  "  ;
    std::cin >> max_p2;
    while (max_p2 != std::round(max_p2) || max_p2 <= 0) {
        std::cout << "Enter the maximum grade on project 2:  " ;
        std::cin >> max_p2;
    }

    double user_p2;
    std::cout << "Enter your grade on project 2: "  ;
    std::cin >> user_p2;
    while (user_p2 < 0 || user_p2 > max_p2) {
        std::cout << "Enter your grade on project 2: " ;
        std::cin >> user_p2;
    }

    // PROJECT 3
        
    double max_p3;
    std::cout << "Enter the maximum grade on project 3:  "  ;
    std::cin >> max_p3;
    while (max_p3 != std::round(max_p3) || max_p3 <= 0) {
        std::cout << "Enter the maximum grade on project 3:  " ;
        std::cin >> max_p3;
    }

    double user_p3;
    std::cout << "Enter your grade on project 3: "  ;
    std::cin >> user_p3;
    while (user_p3 < 0 || user_p3 > max_p3) {
        std::cout << "Enter your grade on project 3: " ;
        std::cin >> user_p3;
    }

    // PROJECT 4
        
    double max_p4;
    std::cout << "Enter the maximum grade on project 4:  "  ;
    std::cin >> max_p4;
    while (max_p4 != std::round(max_p4) || max_p4 <= 0) {
        std::cout << "Enter the maximum grade on project 4:  " ;
        std::cin >> max_p4;
    }

    double user_p4;
    std::cout << "Enter your grade on project 4: "  ;
    std::cin >> user_p4;
    while (user_p4 < 0 || user_p4 > max_p4) {
        std::cout << "Enter your grade on project 4: " ;
        std::cin >> user_p4;
    }

    // PROJECT 5
        
    double max_p5;
    std::cout << "Enter the maximum grade on project 5:  "  ;
    std::cin >> max_p5;
    while (max_p5 != std::round(max_p5) || max_p5 <= 0) {
        std::cout << "Enter the maximum grade on project 5:  " ;
        std::cin >> max_p5;
    }

    double user_p5;
    std::cout << "Enter your grade on project 5: "  ;
    std::cin >> user_p5;
    while (user_p5 < 0 || user_p5 > max_p5) {
        std::cout << "Enter your grade on project 5: " ;
        std::cin >> user_p5;
    }

    // INDIVIUAL CALCULATIONS

    double final_grade;
    final_grade = 100 * (user_final / max_final);

    double term_grade;
    term_grade = 100 * (user_term / max_term);

    double p1_grade;
    p1_grade = 100 * (user_p1 / max_p1);

    double p2_grade;
    p2_grade = 100 * (user_p2 / max_p2);

    double p3_grade;
    p3_grade =  100 * (user_p3 / max_p3);

    double p4_grade;
    p4_grade = 100 * (user_p4 / max_p4);

    double p5_grade;
    p5_grade = 100 * (user_p5 / max_p5);
    
    // EXAMINATION WEIGHTED AVERAGE

    double exam_grade;
    exam_grade = (0.75 * final_grade) + (0.25 * term_grade);

    // PROJECTS GRADE

    double project_grade;
    project_grade = (0.2 * p1_grade) + (0.2 * p2_grade) + (0.2 * p3_grade) + (0.2 * p4_grade) + (0.2 * p5_grade);

    // FINAL GRADE CALCULATION

    double exam_grade_40;
    exam_grade_40 = exam_grade;
    
    double exam_grade_60;
    exam_grade_60 = (0.67 * exam_grade) + (0.33 * project_grade);

    double grade;
    grade = (exam_grade - 40) / 20.0;
    
    double exam_grade_50;
    exam_grade_50 = exam_grade_40 + (grade * (exam_grade_60 - exam_grade_40));


    if (exam_grade <= 40){
        std::cout << "Final Grade : " << std::round ( exam_grade_40 + 1e-12) << std::endl;
    }   else if (exam_grade >= 60) {
        std::cout << "Final Grade : " << std::round ( exam_grade_60 + 1e-12) << std::endl;
    }   else {
        std::cout << "Final Grade : " << std::round ( exam_grade_50 + 1e-12) << std::endl;
    }

    return 0;
}