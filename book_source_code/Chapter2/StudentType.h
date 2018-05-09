class StudentType : public PersonType {
  public:
    string GetStatus() const;
    void Initialize(string, DateType, string);

  private:
    string status;
};
