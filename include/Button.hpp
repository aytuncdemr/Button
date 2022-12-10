#ifndef _BUTTON_HPP_
#define _BUTTON_HPP_

#include <SFML/Graphics.hpp>
#include <functional>

class Button{

    sf::RectangleShape m_button_shape;

    sf::Texture m_button_texture;

    sf::Text m_button_text;

    sf::Font m_font;

    uint32_t m_button_type;

    bool m_validitiy_left_mouse_button;
    bool m_validitiy_right_mouse_button;
    bool m_validitiy_middle_mouse_button;

    std::function<void()> m_lambda_function;

    public:

        Button(const sf::Vector2f &button_position,const sf::Vector2f &button_size,const sf::Vector2f &text_position,const std::string &text_string,const std::string &font_name,const uint32_t &character_size = 32);


        sf::RectangleShape& get_button_shape();
        sf::Text& get_button_text();
        sf::Texture& get_button_texture();


        void set_button_position(const sf::Vector2f &button_position);
        void set_button_fill_color(const sf::Color &button_color);        
        void set_button_outline_color(const sf::Color &button_outline_color);
        void set_button_outline_thickness(const uint32_t &button_thickness);


        void set_text_position(const sf::Vector2f &text_position);
        void set_text_fill_color(const sf::Color &text_color);        
        void set_text_character_size(const uint32_t &text_size);
        void set_text_outline_color(const sf::Color &text_outline_color);
        void set_text_outline_thickness(const uint32_t &text_outline_thickness);


        uint32_t &get_button_type();
        void set_button_type(const uint32_t &button_type);


        bool is_clicked(sf::RenderWindow &window);
        void accept_left_mouse_button(const bool &validity);
        void accept_right_mouse_button(const bool &validity);
        void accept_midde_mouse_button(const bool &validity);

        void set_action_lambda(const std::function<void()> &lambda_function);
        void execute_action();

        void set_button_texture(const std::string &texture_name);

        void draw_to(sf::RenderWindow &window);

};

#endif