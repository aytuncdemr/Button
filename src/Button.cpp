#include "Button.hpp"


Button::Button(const sf::Vector2f &button_position,const sf::Vector2f &button_size,const sf::Vector2f &text_position,const std::string &text_string,const std::string &font_name,const uint32_t &character_size):m_button_shape{button_size},m_validitiy_left_mouse_button{true},m_validitiy_middle_mouse_button{false},m_validitiy_right_mouse_button{false}{
    
    m_button_shape.setPosition(button_position);

    m_button_text.setPosition(text_position);

    m_font.loadFromFile(font_name);

    m_button_text.setFont(m_font);

    m_button_text.setString(text_string);

    m_button_text.setCharacterSize(character_size);

}

sf::RectangleShape& Button::get_button_shape(){


    return m_button_shape;
}

sf::Text& Button::get_button_text(){

    
    return m_button_text;
}

sf::Texture& Button::get_button_texture(){


    return m_button_texture;
}

void Button::set_button_position(const sf::Vector2f &button_position){

    m_button_shape.setPosition(button_position);
    
}

void Button::set_button_fill_color(const sf::Color &button_color){

    m_button_shape.setFillColor(button_color);
    
}

void Button::set_button_outline_color(const sf::Color &button_outline_color){

    m_button_shape.setOutlineColor(button_outline_color);
    
}

void Button::set_button_outline_thickness(const uint32_t &button_thickness){

    m_button_shape.setOutlineThickness(button_thickness);

}

void Button::set_text_position(const sf::Vector2f &text_position){

    m_button_text.setPosition(text_position);
    
}

void Button::set_text_fill_color(const sf::Color &text_color){

    m_button_text.setFillColor(text_color);
    
}

void Button::set_text_character_size(const uint32_t &text_size){

    m_button_text.setCharacterSize(text_size);
    
}

void Button::set_text_outline_color(const sf::Color &text_outline_color){

    m_button_text.setOutlineColor(text_outline_color);
    
}

void Button::set_text_outline_thickness(const uint32_t &text_outline_thickness){

    m_button_text.setCharacterSize(text_outline_thickness);
    
}

uint32_t& Button::get_button_type(){


    return m_button_type;
}

void Button::set_button_type(const uint32_t &button_type){

    m_button_type = button_type;
    
}

bool Button::is_clicked(sf::RenderWindow &window){

    sf::Vector2i mouse_position = sf::Mouse::getPosition(window);

    sf::Vector2f button_shape_position = m_button_shape.getPosition();

    sf::Vector2f button_shape_size = m_button_shape.getSize();

    if(mouse_position.x >= button_shape_position.x and mouse_position.x <= button_shape_position.x + button_shape_size.x)
        if(mouse_position.y >= button_shape_position.y and mouse_position.y <= button_shape_position.y + button_shape_size.y){

            if(m_validitiy_left_mouse_button and sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                return true;

            else if(m_validitiy_middle_mouse_button and sf::Mouse::isButtonPressed(sf::Mouse::Button::Middle))
                return true;

            else if(m_validitiy_right_mouse_button and sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
                return true;

        }

    return false;
}

void Button::accept_left_mouse_button(const bool &validity){
    
    m_validitiy_left_mouse_button = validity;

}

void Button::accept_right_mouse_button(const bool &validity){
    
    m_validitiy_right_mouse_button = validity;

}

void Button::accept_midde_mouse_button(const bool &validity){

    m_validitiy_middle_mouse_button = validity;
    
}

void Button::set_action_lambda(const std::function<void()> &lambda_function){

    m_lambda_function = lambda_function;
    
}

void Button::execute_action(){

    m_lambda_function();
    
}

void Button::set_button_texture(const std::string &texture_name){

    m_button_texture.loadFromFile(texture_name);
    
    m_button_shape.setTexture(&m_button_texture);

}

void Button::draw_to(sf::RenderWindow &window){

    window.draw(m_button_shape);

    window.draw(m_button_text);
    
}

