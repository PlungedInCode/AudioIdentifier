#include "ShazamUI.hpp"

#include <iostream>

AudioIdentifier::AudioIdentifier(int width, int height) {
  InitWindow(width, height);
  InitFont();
  InitUI();
}

void AudioIdentifier::InitWindow(int width, int height) {
  window_.create(sf::VideoMode(400, 700), "AudioIdentifier", sf::Style::Close);

}

void AudioIdentifier::InitFont() {
  font_ = std::make_unique<sf::Font>();
  if (font_->loadFromFile(FONT_PATH)) {
    LOG_TRACE("Font loaded");
  } else {
    LOG_ERROR("Failed to load font");
    window_.close();
  }
}

void AudioIdentifier::InitUI() {
  label_.setFont(*font_.get());
  label_.setString("Music Finder");
  label_.setFillColor(sf::Color::Black);
  label_.setCharacterSize(24);
  label_.setOrigin(label_.getLocalBounds().width / 2,
                   label_.getLocalBounds().height / 2);
  label_.setPosition(window_.getSize().x / 2, 50.f);
  data_ = std::make_unique<PopUp>(window_.getSize().x, 200, window_.getSize().y);
  shape_ = std::make_unique<Button>(window_.getSize().x / 2,
                                    window_.getSize().y / 2, 100.f);
}

void AudioIdentifier::Run() {
  while (window_.isOpen()) {
    HandleEvents();
    Update();
    Render();
  }
}

void AudioIdentifier::HandleEvents() {
  sf::Event event;
  while (window_.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window_.close();
    } else if (event.type == sf::Event::KeyPressed) {
      HandleKeyPress(event.key.code);
    }
  }
}

void AudioIdentifier::HandleKeyPress(sf::Keyboard::Key key) {
  switch (key) {
    case sf::Keyboard::Enter:
      HandleEnterKeyPress();
      break;
    case sf::Keyboard::Space:
      data_->ChangeState();
      break;
    default:
      break;
  }
}

void AudioIdentifier::HandleEnterKeyPress() {
  // if (!recorder.IsRecording()) {
    shape_->ChangeState();
    recording_ = true;
  // }
}

void AudioIdentifier::Update() {
  shape_->Update();
  // if (recording) {
  //   handleRecording();
  // }
}

void AudioIdentifier::HandleRecording() {
  // recorder.StartRecording(1);
  // std::pair<std::string, std::string> matches = GetMatches(recorder.GetData());
  data_->SetData("Unknow", "Unknown");
  // recording = false;
  shape_->ChangeState();
  data_->ChangeState();
}

void AudioIdentifier::Render() {
  window_.clear(sf::Color::White);
  window_.draw(*shape_);
  window_.draw(label_);
  window_.draw(*data_);
  window_.display();
}