#define RAYON_TERRE 6371.0 // Rayon de la Terre

// Structure BorneElectrique
typedef struct {
    int id;
    int nbVoitures;
    int nbVoituresMax;
    double latitude;
    double longitude;
} BorneElectrique;
