#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <random>

#include "abcgOpenGL.hpp"

// Definir qual o comportamento da minha janela
class Window : public abcg::OpenGLWindow {
protected:
  void onCreate() override; // Chamado quando a janela é criada (Bom lugar para colocar inicializacoes)
  void onPaint() override;
  void onPaintUI() override; 
  void onResize(glm::ivec2 const &size) override; // Chamado toda vez que a janela é redimensionada
  void onDestroy() override; // Chamado quando a janela é fechada (Bom lugar para colocar finalizacoes)
// COmandos que comecam com "GL" sao da API OpenGL
private:
  glm::ivec2 m_viewportSize{};

  GLuint m_VAO{}; 
  GLuint m_VBOVertices{}; // Buffers de vertices
  GLuint m_program{};

  std::default_random_engine m_randomEngine;
  std::array<glm::vec2, 3> const m_points{{{0, 1}, {-1, -1}, {1, -1}}};
  glm::vec2 m_P{};

  void setupModel();
};

#endif