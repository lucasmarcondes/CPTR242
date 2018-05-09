void StudentType::Initialize(string newName, DateType newBirthdate, string newStatus) {
    status = newStatus;
    PersonType::Initialize(newName, newBirthdate);
}

string StudentType::GetStatus() const {
    return status;
}
