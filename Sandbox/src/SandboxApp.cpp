#include <Nugget.h>


class ExempleLayer : public Nugget::Layer 
{
public:
	ExempleLayer() 
		: Layer("Exemple") 
	{
	}

	void OnUpdate() override
	{
		NG_INFO("ExempleLayer::OnUpdate");
	}

	void OnEvent(Nugget::Event& e) override
	{
		NG_TRACE("{0}", e);
	}
};

class Sandbox : public Nugget::Application
{
public:
	Sandbox() 
	{
		PushLayer(new ExempleLayer());
	}
	~Sandbox() {}
};

Nugget::Application* Nugget::CreateApplication() 
{
	return new Sandbox();
}