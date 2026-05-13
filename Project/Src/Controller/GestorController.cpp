#include "Project\Headers\Controller\GestorController.h"

GestorController::GestorController(CamiaoContainer *camiao, CamionistaContainer *camionista, CargaContainer *carga, RotaContainer *rota, GestorService *service) {
    this->camiaoContainer = camiao;
    this->camionistaContainer = camionista;
    this->cargaContainer = carga;
    this->rotaContainer = rota;
    this->service = service;
}
