#include "render_process.h"

#include "ipc/ipc_channel.h"
#include "ipc/ipc_message.h"

namespace content {


RenderProcess::RenderProcess(const IPC::ChannelHandle& channel_handle,
    const scoped_refptr<base::SingleThreadTaskRunner>& ipc_task_runner)
{
	channel_ = IPC::ChannelProxy::Create(channel_handle, IPC::Channel::MODE_CLIENT, this, ipc_task_runner);
}

RenderProcess::~RenderProcess()
{
	
}


bool RenderProcess::Send(IPC::Message* msg)
{
	return channel_->Send(msg);
}

bool RenderProcess::OnMessageReceived(const IPC::Message& message)
{
	return true;
}

void RenderProcess::OnChannelConnected(int32_t peer_pid)
{
	
}

void RenderProcess::AddFilter(IPC::MessageFilter* filter)
{
    channel_->AddFilter(filter);
}

void RenderProcess::RemoveFilter(IPC::MessageFilter* filter)
{
    channel_->RemoveFilter(filter);
}

}