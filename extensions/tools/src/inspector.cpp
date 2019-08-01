#include <tools/inspector.h>
#include <tools/neko_editor.h>
#include <imgui.h>
#include <misc/cpp/imgui_stdlib.h>

namespace editor
{

void Inspector::ShowEntityInfo(neko::Entity entity)
{
    if (entity == neko::INVALID_ENTITY)
        return;

    auto& entityManager = nekoEditor_.GetEntityManager();
    auto& sceneManager = nekoEditor_.GetSceneManager();

    ImGui::InputText("Entity Name: ", &sceneManager.GetCurrentScene().entitiesNames[entity]);
    if (entityManager.HasComponent(entity, neko::EntityMask(neko::NekoComponentType::POSITION2D)))
    {
        if (ImGui::CollapsingHeader("Position2d Component"))
        {
            auto& positionManager = nekoEditor_.GetPositionManager();
            auto& pos = positionManager.GetComponent(entity);
            float posRaw[2] = {pos.x, pos.y};
            if (ImGui::InputFloat2("Position", posRaw))
            {
                positionManager.SetComponent(entity, sf::Vector2f(posRaw[0], posRaw[1]));
            }
        }
    }

    if (entityManager.HasComponent(entity, neko::EntityMask(neko::NekoComponentType::SCALE2D)))
    {
        if (ImGui::CollapsingHeader("Scale2d Component"))
        {
            auto& scaleManager = nekoEditor_.GetScaleManager();
            auto& scale = scaleManager.GetComponent(entity);
            float scaleRaw[2] = {scale.x, scale.y};
            if (ImGui::InputFloat2("Scale", scaleRaw))
            {
                scaleManager.SetComponent(entity, sf::Vector2f(scaleRaw[0], scaleRaw[1]));
            }
        }
    }

    if (entityManager.HasComponent(entity, neko::EntityMask(neko::NekoComponentType::ANGLE2D)))
    {
        if (ImGui::CollapsingHeader("Angle2d Component"))
        {
            auto& angleManager = nekoEditor_.GetAngleManager();
            auto& angle = angleManager.GetComponent(entity);
            if (ImGui::InputFloat("Angle", &angle))
            {
                angleManager.SetComponent(entity, angle);
            }
        }
    }
    if (entityManager.HasComponent(entity, neko::EntityMask(neko::NekoComponentType::SPRITE2D)))
    {
        if (ImGui::CollapsingHeader("Sprite2d Component"))
        {
            auto& spriteManager = nekoEditor_.GetSpriteManager();
            auto& textureManager = nekoEditor_.GetTextureManager();
            auto& sprite = spriteManager.GetComponent(entity);

            const auto& textureName = textureManager.GetTexturePath(sprite.textureId);
            if(ImGui::Button(textureName.c_str()))
            {
                ImGui::OpenPopup("Texture Popup");

            }
            ImGui::SameLine();
            ImGui::Text("Texture");

            if (ImGui::BeginPopup("Texture Popup"))
            {
                ImGui::Text("Texture Browser");
                ImGui::Separator();
                if(ImGui::Selectable("No Texture"))
                {
                    spriteManager.CopyTexture(neko::INVALID_INDEX, entity, 1);
                }
                for(neko::Index i = 0 ; i < textureManager.GetTextureCount();i++)
                {
                    if(ImGui::Selectable(textureManager.GetTexturePath(i).c_str()))
                    {
                        spriteManager.CopyTexture(i, entity, 1);
                    }
                }
                ImGui::EndPopup();
            }
        }
    }
    if (entityManager.HasComponent(entity, neko::EntityMask(neko::NekoComponentType::BODY2D)))
    {

        if (ImGui::CollapsingHeader("Body2d Component"))
        {
            auto& bodyDefManager = nekoEditor_.GetBodyDefManager();
            auto& bodyDef = bodyDefManager.GetComponent(entity);
            const char* bodyTypeMap[3] =
            {
                "Static",
                "Kinematic",
                "Dynamic"
            };
            ImGui::Combo("Body Type", (int*)(&bodyDef.type), bodyTypeMap, 3);
            ImGui::InputFloat("Gravity Scale", &bodyDef.gravityScale);

        }
    }

    if (ImGui::Button("Add Component"))
        ImGui::OpenPopup("Component Popup");
    const static std::map<neko::NekoComponentType, std::string> componentNameMap =
    {
        {neko::NekoComponentType::POSITION2D, "Position 2D"},
        {neko::NekoComponentType::SCALE2D,    "Scale 2D"},
        {neko::NekoComponentType::ANGLE2D,    "Angle 2D"},
        {neko::NekoComponentType::SPRITE2D,   "Sprite 2D"},
        {neko::NekoComponentType::BODY2D,     "Body 2D"},
    };

    ImGui::SameLine();
    if (ImGui::BeginPopup("Component Popup"))
    {
        ImGui::Text("Component");
        ImGui::Separator();
        for (auto& component: componentNameMap)
        {
            if (entityManager.HasComponent(entity, neko::EntityMask(component.first)))
                continue;
            if (ImGui::Selectable(component.second.c_str(), false))
            {
                entityManager.AddComponentType(entity, neko::EntityMask(component.first));
                switch(component.first)
                {
                    case neko::NekoComponentType::SCALE2D:
                    {
                        auto& scaleManager = nekoEditor_.GetScaleManager();
                        scaleManager.AddComponent(entityManager, entity);
                        break;
                    }
                    case neko::NekoComponentType::POSITION2D:
                    {
                        auto& positionManager = nekoEditor_.GetPositionManager();
                        positionManager.AddComponent(entityManager, entity);
                        break;
                    }
                    case neko::NekoComponentType::ANGLE2D:
                    {
                        auto& angleManager = nekoEditor_.GetAngleManager();
                        angleManager.AddComponent(entityManager, entity);
                        break;
                    }
                    case neko::NekoComponentType::SPRITE2D:
                    {
                        auto& spriteManager = nekoEditor_.GetSpriteManager();
                        spriteManager.AddComponent(entityManager, entity);
                        break;
                    }
                    case neko::NekoComponentType::SPINE_ANIMATION:
                    {
                        break;
                    }
                    case neko::NekoComponentType::BODY2D:
                    {
                        auto& bodyDefManager = nekoEditor_.GetBodyDefManager();
                        bodyDefManager.AddComponent(entityManager, entity);
                        break;
                    }
                    case neko::NekoComponentType::COLLIDER2D:
                        break;
                    case neko::NekoComponentType::CONVEX_SHAPE2D:
                        break;
                    default:
                        break;
                }
                ImGui::CloseCurrentPopup();
                break;
            }
        }
        ImGui::EndPopup();
    }
}

void Inspector::BeginWindow()
{
    ImGui::Begin("Inspector", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
}

void Inspector::EndWindow()
{
    ImGui::End();
}
}