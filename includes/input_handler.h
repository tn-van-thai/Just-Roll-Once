class InputHandler{
    public:
        /**
         * @brief Gets the user input and does bound checking
         *
         * @param low the lowest choice player can choose
         * @param high the highest choice player can choose
         * @return A valid choice in the range [low, high].
         */ 
        static int GetChoice(int low, int high);
};