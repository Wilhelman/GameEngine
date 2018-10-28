#include "SDL/include/SDL.h"

#include "PanelInspector.h"
#include "trRenderer3D.h"

#include "trApp.h"
#include "trEditor.h"

#include "GameObject.h"
#include "ComponentMesh.h"
#include "ComponentMaterial.h"
#include "ComponentTransform.h"

PanelInspector::PanelInspector() : Panel("Inspector", SDL_SCANCODE_I)
{
	active = false;
}

PanelInspector::~PanelInspector()
{
}

void PanelInspector::SetDataFrom(Mesh* mesh)
{
}

void PanelInspector::SetDataFrom(Texture * texture)
{
	this->texture = texture;
}

void PanelInspector::Clear()
{
	texture = nullptr;
}

void PanelInspector::Draw()
{
	ImGui::Begin("Inspector", &active);

	GameObject* selected = App->editor->GetSelected();

	if (selected != nullptr) {
		ImGui::Text("GameObject name: %s", selected->GetName());
		ImGui::Separator();
		for (std::list<Component*>::iterator it = selected->components.begin(); it != selected->components.end(); it++) {
			switch ((*it)->GetType())
			{
			case Component::component_type::COMPONENT_TRANSFORM:
			{
				ComponentTransform* trans_co = (ComponentTransform*)(*it);
				float3 position = trans_co->GetTranslation();
				float3 scale = trans_co->GetScale();
				Quat rotation = trans_co->GetRotation();
				if (ImGui::CollapsingHeader("TRANSFORM COMPONENT", ImGuiTreeNodeFlags_DefaultOpen)) {
					ImGui::Text("Position:");
					float pos[3] = { position.x, position.y, position.z };
					ImGui::InputFloat3("##POS", pos, 2);
					ImGui::Text("Rotation:");
					float rot[3] = { rotation.x, rotation.y, rotation.z };
					ImGui::InputFloat3("##ROT", rot, 2);
					ImGui::Text("Scale:");
					float sca[3] = { scale.x, scale.y, scale.z };
					ImGui::InputFloat3("##SCA", sca, 2);
				}
				ImGui::Separator();
				break;
			}
			case Component::component_type::COMPONENT_MESH: 
			{
				ComponentMesh* mesh_co = (ComponentMesh*)(*it);
				const Mesh* mesh = mesh_co->GetMesh();
				if (ImGui::CollapsingHeader("MESH COMPONENT", ImGuiTreeNodeFlags_DefaultOpen)) {
					if (mesh != nullptr) {
						ImGui::Text("Triangles: %i", mesh->face_size);
						ImGui::Text("Vertices: %i", mesh->vertex_size / 3);///bc vertices are stored in x/y/z format!
						ImGui::Text("Indices: %i", mesh->index_size);
						ImGui::Text("UVS: %i", mesh->size_uv);
						ImGui::Text("Source: %s", mesh->path.c_str());
					}
				}
				ImGui::Separator();
				break;
			}
			case Component::component_type::COMPONENT_MATERIAL:
			{
				ComponentMaterial* mat_co = (ComponentMaterial*)(*it);
				const Texture* texture = mat_co->GetTexture();
				if (ImGui::CollapsingHeader("MATERIAL COMPONENT", ImGuiTreeNodeFlags_DefaultOpen)) {
					if (texture != nullptr) {
						ImGui::Text("Source: %s", texture->path.c_str());
						ImGui::Text("Width: %i", texture->width);
						ImGui::Text("Height: %i", texture->height);
						ImGui::Image((ImTextureID)texture->id, ImVec2(200, 200));
					}
				}
				ImGui::Separator();
				break;
			}
			case Component::component_type::COMPONENT_UNKNOWN:
				TR_LOG("Rly?");
				break;
			default:
				break;
			}

		}

	}

	/*if (!meshes.empty()) {
		ImGui::Text("Model name: %s", meshes.front()->name.c_str());
		ImGui::Text("Source: %s", meshes.front()->path.c_str());

		if (ImGui::CollapsingHeader("Transformation")) {
			ImGui::Text("GameObject read-only values");
			ImGui::Separator();
			ImGui::Text("Position:");
			float pos[3] = { meshes.front()->position.x,meshes.front()->position.y, meshes.front()->position.z };
			ImGui::InputFloat3("", pos, 2);
			ImGui::Text("Rotation:");
			float rot[3] = { meshes.front()->rotation.x,meshes.front()->rotation.y, meshes.front()->rotation.z };
			ImGui::InputFloat3("", rot, 2);
			ImGui::Text("Scale:");
			float sca[3] = { meshes.front()->scale.x,meshes.front()->scale.y, meshes.front()->scale.z };
			ImGui::InputFloat3("", sca, 2);
		}

		if (ImGui::CollapsingHeader("Mesh info")) {

			// todo: remove this total calculator when we have the gameobject class
			int total_vertices = 0, total_indices = 0, total_uvs = 0, total_faces = 0;
			for (uint i = 0; i < meshes.size(); i++)
			{
				total_vertices += meshes.at(i)->vertex_size / 3;///bc vertices are stored in x/y/z format!
				total_indices += meshes.at(i)->index_size;
				total_uvs += meshes.at(i)->size_uv;
				total_faces += meshes.at(i)->face_size;
			}

			ImGui::Text("Total triangles: %i", total_faces);
			ImGui::Text("Total vertices: %i", total_vertices);
			ImGui::Text("Total indices: %i", total_indices);
			ImGui::Text("Total UVS: %i", total_uvs);
			ImGui::Separator();

			ImGui::Text("Number of meshes: %i", meshes.size());
			if (meshes.size() > 1) {
				for (uint i = 0; i < meshes.size(); i++)
				{
					std::string tmp = "Info Mesh ";
					tmp = tmp + std::to_string(i + 1);
					if (ImGui::CollapsingHeader(tmp.c_str()))
					{
						ImGui::Text("Triangles: %i", meshes.at(i)->face_size);
						ImGui::Text("Vertices: %i", meshes.at(i)->vertex_size / 3);///bc vertices are stored in x/y/z format!
						ImGui::Text("Indices: %i", meshes.at(i)->index_size);
						ImGui::Text("UVS: %i", meshes.at(i)->size_uv);
					}
				}
			}
			
			
		}

		if (texture != nullptr) {
			if (ImGui::CollapsingHeader("Texture")) {
				ImGui::Text("Source: %s", texture->path.c_str());
				ImGui::Text("Width: %i", texture->width);
				ImGui::Text("Height: %i", texture->height);
				ImGui::Image((ImTextureID)texture->id, ImVec2(200, 200));
			}
		}
		
	}*/

	ImGui::End();
}