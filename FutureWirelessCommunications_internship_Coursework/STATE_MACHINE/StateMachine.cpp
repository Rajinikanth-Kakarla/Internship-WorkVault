class DecadeCounter {
public:
  DecadeCounter(){
    current_state = 0;
  }

  void transition() {
    if (clock) {
      current_state = get_next_state();
    }
  }

  void setClock(bool clk) {
    clock = clk;
  }

  int get_current_state() {
    return current_state;
  }

  int get_next_state() {
    int transitions[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    return transitions[current_state];
  }
private:
  int current_state;
  bool clk;
};

  void printBinary(int num) {
    for (int i = 7; i >= 0; i--) {
      Serial.print((num & (1 << i)) ? '1' : '0');
    }
  }

DecadeCounter counter;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int current_state = counter.get_current_state();
  int next_state = counter.get_next_state();
  counter.setClock(true);
  delay(100);
  counter.transition();
  counter.setClock(false);
  delay(1000);
}
